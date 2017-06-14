from datetime import datetime

from .header42 import *
from .objects import *

G_tabalign = 7
G_tabalignenum = 4

def alignOnTab(name, atab = 6, btab = 1):
	text = '\t' * btab
	text += name
	atab -= btab + int(len(name) / 4)
	if atab > 0:
		text += '\t' * atab
	return text

def generate_headers(dirname):
	groups = build_groups()
	objs = build_objects(groups)
	print_objects(objs)
	name = "rt_objects_gen.h"
	fname = dirname + "/" + name
	# object file
	f = open(fname, 'w')
	f.write(gen_42header(name,
		"qloubier", "marvin@student.42.fr", datetime.now()))
	f.write("#ifndef " + name.upper().replace('.','_') + "\n")
	f.write("# define " + name.upper().replace('.','_') + "\n")
	# type enum
	name = "rt_proto_gen.h"
	fname = dirname + "/" + name
	ftype = open(fname, 'w')
	ftype.write(gen_42header(name,
		"qloubier", "marvin@student.42.fr", datetime.now()))
	ftype.write("#ifndef " + name.upper().replace('.','_') + "\n")
	ftype.write("# define " + name.upper().replace('.','_') + "\n\n")
	ftype.write("""# include "libft.h"\n\n""")
	ftype.write(alignOnTab("typedef enum", G_tabalign, 0) + "e_rt_object_type\n{\n")
	# type tab
	name = "rt_typetab_gen.h"
	fname = dirname + "/" + name
	fttab = open(fname, 'w')
	fttab.write(gen_42header(name,
		"qloubier", "marvin@student.42.fr", datetime.now()))
	fttab.write("#ifndef " + name.upper().replace('.','_') + "\n")
	fttab.write("# define " + name.upper().replace('.','_') + "\n\n")
	fttab.write("""# include "rt_object.h"\n\n""")
	fttab.write("""# include "rt_render.h"\n\n""")
	obttab = ""
	obttablen = 0
	# includes
	f.write("""\n# include "mathex/vector.h"\n""")
	f.write("""# include "mathex/matrix.h"\n""")
	f.write("""# include "rt_prototype.h"\n\n""")
	ctext = alignOnTab("struct", G_tabalign, 0) + "s_rt_object\n{\n"
	gObOffset = 0
	gObprop = 0
	vtabtxt = ""
	for aprop in G_basicproperty:
		ctext += aprop.mkcvar(None, G_tabalign)
		gObOffset += int(aprop)
		gObprop += 1
	ctext += "};\n\n"
	f.write(ctext)
	allstruct = alignOnTab("union", G_tabalign, 0) + "u_rt_objectdata\n{\n"
	for akey in objs[0]:
		anob = objs[akey]
		ctext = ""
		cprstext = ""
		if anob["cstruct"]:
			valoffset = gObOffset
			validx = 0
			allstruct += alignOnTab("struct s_" + anob["cname"], G_tabalign) + akey + ";\n"
			ctext = alignOnTab("struct", G_tabalign, 0) + "s_"+anob["cname"] + "\n{\n"
			for aprop in G_basicproperty:
				ctext += aprop.mkcvar(None, G_tabalign)
			for aprop in anob["property"]:
				ctext += aprop.mkcvar(None, G_tabalign)
				tmps = aprop.mkval(valoffset, validx)
				valoffset += int(aprop)
				if tmps:
					cprstext += '\n' + tmps + ','
					validx += 1
			ctext += "};\n\n"
			obttab += '{"' + anob["cenum"] + '", ' + anob["cenum"] + ', 0, ' + str(valoffset) + ', '
			if cprstext:
				obttab += "\n&g_elm_" + akey + ', object_default_' + akey + ',\n'
			else:
				obttab += '\nNULL, object_default_' + akey + ',\n'
			if anob["intersect"]:
				obttab += ('intersect_'+akey+', getnor_'+akey+', gettan_'+akey
					+', object_bound_'+akey+'},\n')
			else:
				obttab += 'NULL, NULL, NULL, NULL},\n'
			obttablen += 1;
		if ctext:
			f.write(ctext)
		if cprstext:
			cprstext = (alignOnTab("static const t_val", G_tabalign, 0)
				+ "g_vtab_"+ akey + "[" + str(validx) + "] = {"
				+ cprstext[:-1] + "\n};\n\n")
			cprstext += (alignOnTab("static const t_elm", G_tabalign, 0)
				+ "g_elm_"+akey + "= {" + '"'+akey+'",\n'
				+ 'sizeof(struct s_'+anob["cname"]+'), ' + str(validx - 1) + ', '
				+ str(validx) + ', (t_val *)(t_ul)g_vtab_'+akey
				+ ',\nNULL, NULL, ft_vparse_null, NULL};\n\n')
			f.write(cprstext)
		ftype.write(alignOnTab(anob["cenum"], G_tabalignenum, 1) + "= " + hex(anob["id"]) + ",\n")
	allstruct += "};\n\n"
	f.write(allstruct)
	for akey in groups[0]:
		anob = groups[akey]
		ctext = alignOnTab(anob["cenum"], G_tabalignenum, 1) + "= "
		for k in anob["childs"]:
			ctext += groups[k]["cenum"] + " | "
		for k in anob["objects"]:
			ctext += objs[k]["cenum"] + " | "
		ctext = ctext[:-3] + ",\n"
		ftype.write(ctext);
	ftype.write(alignOnTab("}", G_tabalign, 0) + "t_rtobt;\n\n");
	# close object file
	f.write("#endif\n")
	f.close()
	# close type enum file
	ftype.write("#endif\n")
	ftype.close()
	# close type enum file
	fttab.write("# define RT_OBT_TAB_LEN " + str(obttablen) + "\n\n")
	fttab.write(alignOnTab("static const t_rtobind", G_tabalign, 0))
	fttab.write("g_obt_tab[" + str(obttablen) + "] = {\n")
	fttab.write(obttab + "};\n\n")
	fttab.write("#endif\n")
	fttab.close()

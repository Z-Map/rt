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
	ftype.write(alignOnTab("typedef enum", G_tabalign, 0) + "e_rt_object_type\n{\n")
	# includes
	f.write("""\n# include "mathex/vector.h"\n""")
	f.write("""# include "mathex/matrix.h"\n""")
	f.write("""# include "rt_prototype.h"\n\n""")
	ctext = alignOnTab("struct", G_tabalign, 0) + "s_rt_object\n{\n"
	for apkey,aprop in G_basicproperty.items():
		ctext += aprop.mkcvar(apkey, G_tabalign)
	ctext += "};\n\n"
	f.write(ctext)
	allstruct = alignOnTab("union", G_tabalign, 0) + "u_rt_objectdata\n{\n"
	for akey,anob in objs.items():
		ctext = ""
		if anob["cstruct"]:
			allstruct += alignOnTab("struct s_" + anob["cname"], G_tabalign) + akey + ";\n"
			ctext = alignOnTab("struct", G_tabalign, 0) + "s_"+anob["cname"] + "\n{\n"
			for apkey,aprop in G_basicproperty.items():
				ctext += aprop.mkcvar(apkey, G_tabalign)
			for apkey,aprop in anob["property"].items():
				ctext += aprop.mkcvar(apkey, G_tabalign)
			ctext += "};\n\n"
		if ctext:
			f.write(ctext)
		ftype.write(alignOnTab(anob["cenum"], G_tabalignenum, 1) + "= " + hex(anob["id"]) + ",\n")
	allstruct += "};\n\n"
	f.write(allstruct)
	for akey,anob in groups.items():
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

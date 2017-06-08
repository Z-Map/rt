from . import obtype

ObT = obtype.Obtype

G_basicproperty = (
	ObT("instances", "size_t"),
	ObT("type", "ul"),
	ObT("usercfg", "ul"),
	ObT("name", "char"),
	ObT("intersect", "void"),
)

G_groups =(
	{
		"name" : "visible",
		"group" : "valid",
		"property" : (
			ObT("lim.x", "t_v2f"),
			ObT("lim.y", "t_v2f"),
			ObT("lim.z", "t_v2f"),
			ObT("material", "t_rtmat"),
		)
	},
	{
		"name" : "light",
		"group" : "valid",
		"property" : (
			ObT("intensity", "f"),
			ObT("radius", "f"),
		)
	},
	{
		"name" : "tool",
		"group" : "valid",
	},
	{
		"name" : "valid"
	}
)
G_objects = (
	{
		"name" : "invalid",
		"id" : 0,
	},
	{
		"name" : "scene",
		"group" : "valid",
		"property" : (
			ObT("ambient_light", "t_rtmat"),
			ObT("skybox", "t_rtmat"),
		)
	},
	{
		"name" : "empty",
		"group" : "tool",
		"property" : (
			ObT("subtree", "void"),
			ObT("size", "double"),
		)
	},
	{
		"name" : "camera",
		"group" : "tool",
		"property" : (
			ObT("fov", "t_v2d"),
			ObT("focus", "float"),
			ObT("fstop", "float"),
		)
	},
	{
		"name" : "plan",
		"group" : "visible",
	},
	{
		"name" : "sphere",
		"group" : "visible",
		"property" : (
			ObT("radius", "float"),
			ObT("padding", "int"),
		)
	},
	{
		"name" : "cone",
		"group" : "visible",
		"property" : (
			ObT("angle", "float"),
			ObT("padding", "int"),
		)
	},
	{
		"name" : "cylinder",
		"group" : "visible",
		"property" : (
			ObT("radius", "float"),
			ObT("padding", "int"),
		)
	},
	{
		"name" : "cuboid",
		"group" : "visible",
	},
	{
		"name" : "tris",
		"group" : "visible",
	},
	{
		"name" : "mesh",
		"group" : "visible",
		"property" : (
			ObT("vertex_len", "size_t"),
			ObT("poly_len", "size_t"),
			ObT("vertex", "t_v3f", -1),
			ObT("normale", "t_v3f", -1),
			ObT("uv", "t_v2f", -1),
			ObT("poly", "t_v3ui", -1),
		)
	},
	{
		"name" : "spot",
		"group" : "light",
		"property" : (
			ObT("angle", "float"),
			ObT("padding", "int"),
		)
	},
	{
		"name" : "pointlight",
		"group" : "light",
	},
	{
		"name" : "sunlight",
		"group" : "light",
	},
	{
		"name" : "notype"
	},
)

def print_objects(objs):
	for ob in objs[0]:
		dispstr = ob + " : \n"
		for akey in objs[ob]:
			dispstr += "\t" + akey + " : " + repr(objs[ob][akey]) + "\n"
		print (dispstr)

def build_groups():
	groups = {}
	groups[0] = []
	for anob in G_groups:
		akey = anob["name"]
		groups[0].append(akey)
		groups[akey] = {}
		groups[akey]["cenum"] = akey.upper()
		groups[akey]["parents"] = []
		groups[akey]["childs"] = []
		groups[akey]["property"] = ()
		groups[akey]["objects"] = []
		parent = anob
		while "group" in parent and parent["group"] not in groups[akey]["parents"]:
			groups[akey]["parents"].append(parent["group"])
			nparent = None
			for aob in G_groups:
				if aob["name"] == parent["group"]:
					nparent = aob
			if not nparent:
				break
			parent = nparent
			if "property" in parent:
				groups[akey]["property"] = parent["property"] + groups[akey]["property"]
		if "property" in anob:
			groups[akey]["property"] = groups[akey]["property"] + anob["property"]
	for akey,anob in groups.items():
		if type(akey) != str:
			continue
		for aparent in anob["parents"]:
			groups[aparent]["childs"].append(akey)
	return groups

def build_objects(groups = None):
	if not groups:
		groups = build_groups()
	objs = {}
	objs[0] = []
	obid = 1
	for anob in G_objects:
		akey = anob["name"]
		objs[0].append(akey)
		objs[akey] = {}
		if not "id" in anob:
			objs[akey]["id"] = obid
			obid <<= 1
		else:
			objs[akey]["id"] = anob["id"]
		objs[akey]["cstruct"] = False
		objs[akey]["intersect"] = False
		objs[akey]["property"] = ()
		if "group" in anob and anob["group"] in groups:
			if anob["group"] == "valid" or "valid" in groups[anob["group"]]["parents"]:
				objs[akey]["cstruct"] = True
			groups[anob["group"]]["objects"].append(akey)
			if "property" in groups[anob["group"]]:
				objs[akey]["property"] = groups[anob["group"]]["property"]
			if anob["group"] == "visible":
				objs[akey]["intersect"] = True
		if "property" in anob:
			objs[akey]["property"] = objs[akey]["property"] + anob["property"]
		if objs[akey]["property"] == ():
			objs[akey]["cstruct"] = False
		objs[akey]["cname"] = "rt" + akey
		objs[akey]["cenum"] = akey.upper()
	return (objs)

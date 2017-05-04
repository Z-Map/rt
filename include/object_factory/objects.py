from . import obtype

ObT = obtype.Obtype

G_basicproperty = {
	"instances" : ObT("size_t"),
	"type" : ObT("ul"),
	"usercfg" : ObT("ul"),
	"name" : ObT("char")
}

G_groups = {
	"visible" : {
		"group" : "valid",
		"property" : {
			"material" : ObT("t_rtmat")
		}
	},
	"light" : {
		"group" : "valid",
		"property" : {
			"material" : ObT("t_rtmat"),
			"intensity" : ObT("f"),
			"radius" : ObT("f")
		}
	},
	"tool" : {
		"group" : "valid",
	},
	"valid" : {}
}
G_objects = {
	"invalid" : {
		"id" : 0,
	},
	"scene" : {
		"group" : "valid",
		"property" : {
			"ambient_light" : ObT("t_rtmat"),
			"skybox" : ObT("t_rtmat")
		}
	},
	"empty" : {
		"group" : "tool",
		"property" : {
			"subtree" : ObT("void"),
			"size" : ObT("float")
		}
	},
	"camera" : {
		"group" : "tool",
		"property" : {
			"fov" : ObT("t_v2f"),
			"focus" : ObT("float")
		}
	},
	"plan" : {
		"group" : "visible",
	},
	"sphere" : {
		"group" : "visible",
		"property" : {
			"radius" : ObT("float")
		}
	},
	"cone" : {
		"group" : "visible",
		"property" : {
			"angle" : ObT("float")
		}
	},
	"cylinder" : {
		"group" : "visible",
		"property" : {
			"radius" : ObT("float")
		}
	},
	"cuboid" : {
		"group" : "visible",
		"property" : {
			"radius" : ObT("float")
		}
	},
	"tris" : {
		"group" : "visible",
	},
	"mesh" : {
		"group" : "visible",
		"property" : {
			"vertex_len" : ObT("size_t"),
			"poly_len" : ObT("size_t"),
			"vertex" : ObT("t_v3f", -1),
			"normale" : ObT("t_v3f", -1),
			"uv" : ObT("t_v2f", -1),
			"poly" : ObT("t_v3ui", -1)
		}
	},
	"spot" : {
		"group" : "light",
		"property" : {
			"angle" : ObT("float")
		}
	},
	"pointlight" : {
		"group" : "light",
	},
	"sunlight" : {
		"group" : "light",
	},
	"notype" : {
	},
}

def print_objects(objs):
	for ob in objs:
		dispstr = ob + " : \n"
		for akey in objs[ob]:
			dispstr += "\t" + akey + " : " + repr(objs[ob][akey]) + "\n"
		print (dispstr)

def build_groups():
	groups = {}
	for akey,anob in G_groups.items():
		groups[akey] = {}
		groups[akey]["cenum"] = akey.upper()
		groups[akey]["parents"] = []
		groups[akey]["childs"] = []
		groups[akey]["property"] = {}
		groups[akey]["objects"] = []
		parent = anob
		while "group" in parent and parent["group"] not in groups[akey]["parents"]:
			groups[akey]["parents"].append(parent["group"])
			parent = G_groups[parent["group"]]
			if "property" in parent:
				for apkey, aprop in parent["property"].items():
					groups[akey]["property"][apkey] = aprop
		if "property" in anob:
			for apkey, aprop in anob["property"].items():
				groups[akey]["property"][apkey] = aprop
	for akey,anob in groups.items():
		for aparent in anob["parents"]:
			groups[aparent]["childs"].append(akey)
	return groups

def build_objects(groups = None):
	if not groups:
		groups = build_groups()
	objs = {}
	obid = 1
	for akey,anob in G_objects.items():
		objs[akey] = {}
		if not "id" in anob:
			objs[akey]["id"] = obid
			obid <<= 1
		else:
			objs[akey]["id"] = anob["id"]
		objs[akey]["cstruct"] = False
		objs[akey]["property"] = {}
		if "group" in anob and anob["group"] in groups:
			if anob["group"] == "valid" or "valid" in groups[anob["group"]]["parents"]:
				objs[akey]["cstruct"] = True
			groups[anob["group"]]["objects"].append(akey)
			if "property" in groups[anob["group"]]:
				for apkey, aprop in groups[anob["group"]]["property"].items():
					objs[akey]["property"][apkey] = aprop
		if "property" in anob:
			for apkey, aprop in anob["property"].items():
				objs[akey]["property"][apkey] = aprop
		if objs[akey]["property"] == {}:
			objs[akey]["cstruct"] = False
		objs[akey]["cname"] = "rt" + akey
		objs[akey]["cenum"] = akey.upper()
	return (objs)

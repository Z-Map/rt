
class Obtype(object):

	def __init__(self, name, typestr, num = 1, etype = "VT_NONE"):
		self.name = name
		self.cname = name.replace(".", "")
		self.pointer = True if num < 0 else False
		self.e_len = num if num > 1 else 1
		self.csufix = "[" + str(num) + "]" if num > 1 else ""
		self.size = 8
		typestr = typestr.strip()
		self.parser_elm = None
		if typestr in ("i", "int", "t_v2i", "t_v3i", "t_v4i"):
			self.ctype = "int"
			self.basetype = "int"
			self.typeletter = "i"
			self.size = 4
			etype = "VT_INT"
			self.parser_elm = "g_el_int"
			if typestr.startswith("t_v"):
				self.e_len *= int(typestr[-2])
				self.ctype = typestr
				etype = "VT_VEC" + (typestr[-2:]).upper()
				self.parser_elm = "g_el_vec" + typestr[-2:]
		elif typestr in ("l", "long"):
			self.ctype = "long"
			self.basetype = "long"
			self.typeletter = "l"
			etype = "VT_LONG"
			self.parser_elm = "g_el_long"
		elif typestr in ("ui", "uint", "t_ui", "t_v2ui", "t_v3ui", "t_v4ui", "t_rgba", "t_rtobt"):
			self.ctype = "unsigned int"
			self.basetype = "unsigned int"
			self.typeletter = "ui"
			self.size = 4
			etype = "VT_UINT"
			self.parser_elm = "g_el_int"
			if typestr.startswith("t_"):
				self.ctype = typestr
				if typestr == "t_rgba":
					etype = "VT_COLOR"
					self.parser_elm = "g_el_col"
			if typestr.startswith("t_v"):
				self.e_len *= int(typestr[-3])
				etype = "VT_VEC" + (typestr[-3:]).upper()
				self.parser_elm = "g_el_vec" + typestr[-3:]
		elif typestr in ("ul", "ulong", "t_ul", "size_t"):
			self.ctype = "size_t" if typestr == "size_t" else "unsigned long"
			self.basetype = "unsigned long"
			self.typeletter = "ul"
			etype = "VT_ULONG"
			self.parser_elm = "g_el_long"
		elif typestr in ("f","float", "t_v2f", "t_v3f", "t_v4f",
			"t_mattf", "t_mat3x2f", "t_mat2f", "t_mat2x3f", "t_mat4f"):
			self.ctype = "float"
			self.basetype = "float"
			self.typeletter = "f"
			self.size = 4
			etype = "VT_FLOAT"
			self.parser_elm = "g_el_float"
			if typestr.startswith("t_v"):
				self.e_len *= int(typestr[-2])
				self.ctype = typestr
				etype = "VT_VEC" + (typestr[-2:]).upper()
				self.parser_elm = "g_el_vec" + typestr[-2:]
			if typestr.startswith("t_mat"):
				if typestr == "t_mattf":
					self.e_len *= 16
				elif typestr[-3] == 'x':
					self.e_len *= int(typestr[-2]) * int(typestr[-4])
				else:
					self.e_len *= int(typestr[-2]) * int(typestr[-2])
				self.ctype = typestr
				etype = "VT_MAT" + (typestr[6:]).upper()
				self.parser_elm = None
		elif typestr in ("d","double", "t_v2d", "t_v3d", "t_v4d"):
			self.ctype = "double"
			self.basetype = "double"
			self.typeletter = "d"
			etype = "VT_DOUBLE"
			self.parser_elm = "g_el_double"
			if typestr.startswith("t_v"):
				self.e_len *= int(typestr[-2])
				self.ctype = typestr
				etype = "VT_VEC" + (typestr[-2:]).upper()
				self.parser_elm = "g_el_vec" + typestr[-2:]
		else:
			if typestr in ("str", "string"):
				typestr = "char"
				self.parser_elm = "g_el_vstr"
			self.ctype = typestr
			self.basetype = "pointer"
			self.typeletter = "p"
			self.pointer = True
			if typestr == "char":
				etype = "VT_STR"
			if typestr == "t_rtobj":
				etype = "VT_OBJECT"
			if typestr == "t_rtmat":
				etype = "VT_MATERIAL"
		self.etype = etype

	def __str__(self):
		ret = self.ctype
		if self.pointer:
			ret = ret + " *"
		ret = ret + self.name + self.csufix
		return (ret)

	def __repr__(self):
		return (self.__str__())

	def __int__(self):
		if self.pointer:
			return 8
		return self.size * self.e_len

	def mkval(self, offset, idx, name = None, sep = ",\n"):
		if not self.parser_elm:
			return ""
		if not name:
			name = self.name
		txt = "(t_val){" + self.etype + ", " + str(offset)
		txt += ", " + str(idx) + ", 0, \"" + name + "\", (t_elm *)(t_ul)(&"
		txt += self.parser_elm + ")}"
		return txt

	def mkcvar(self, name = None, atab = 6, btab = 1):
		if not name:
			name = self.cname
		text = '\t' * btab
		text += self.ctype
		atab -= btab + int(len(self.ctype) / 4)
		if atab > 0:
			text += '\t' * atab
		else:
			text += ' '
		if self.pointer:
			text += '*' + name + ";\n"
		else:
			text += name + self.csufix + ";\n"
		return text

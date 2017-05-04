
class Obtype(object):

	def __init__(self, typestr, num = 1, etype = "PT_NONE"):
		self.pointer = True if num < 0 else False
		self.e_len = num if num > 1 else 1
		self.csufix = "[" + str(num) + "]" if num > 1 else ""
		self.size = 8
		typestr = typestr.strip()
		if typestr in ("i", "int", "t_v2i", "t_v3i", "t_v4i"):
			self.ctype = "int"
			self.basetype = "int"
			self.typeletter = "i"
			self.size = 4
			etype = "PT_INT"
			if typestr.startswith("t_v"):
				self.e_len *= int(typestr[-2])
				self.ctype = typestr
				etype = "PT_VEC" + (typestr[-2:]).upper()
		elif typestr in ("l", "long"):
			self.ctype = "long"
			self.basetype = "long"
			self.typeletter = "l"
			etype = "PT_LONG"
		elif typestr in ("ui", "uint", "t_ui", "t_v2ui", "t_v3ui", "t_v4ui", "t_rgba", "t_rtobt"):
			self.ctype = "unsigned int"
			self.basetype = "unsigned int"
			self.typeletter = "ui"
			self.size = 4
			etype = "PT_UINT"
			if typestr.startswith("t_"):
				self.ctype = typestr
				if typestr == "t_rgba":
					etype = "PT_COLOR"
			if typestr.startswith("t_v"):
				self.e_len *= int(typestr[-3])
				etype = "PT_VEC" + (typestr[-2:]).upper()
		elif typestr in ("ul", "ulong", "t_ul", "size_t"):
			self.ctype = "size_t" if typestr == "size_t" else "unsigned long"
			self.basetype = "unsigned long"
			self.typeletter = "ul"
			etype = "PT_ULONG"
		elif typestr in ("f","float", "t_v2f", "t_v3f", "t_v4f"):
			self.ctype = "float"
			self.basetype = "float"
			self.typeletter = "f"
			self.size = 4
			etype = "PT_FLOAT"
			if typestr.startswith("t_v"):
				self.e_len *= int(typestr[-2])
				self.ctype = typestr
				etype = "PT_VEC" + (typestr[-2:]).upper()
		elif typestr in ("d","double", "t_v2d", "t_v3d", "t_v4d"):
			self.ctype = "double"
			self.basetype = "double"
			self.typeletter = "d"
			etype = "PT_DOUBLE"
			if typestr.startswith("t_v"):
				self.e_len *= int(typestr[-2])
				self.ctype = typestr
				etype = "PT_VEC" + (typestr[-2:]).upper()
		else:
			if typestr in ("str", "string"):
				typestr = "char"
			self.ctype = typestr
			self.basetype = "pointer"
			self.typeletter = "p"
			self.pointer = True
			if typestr == "char":
				etype = "PT_STR"
			if typestr == "t_rtobj":
				etype = "PT_OBJECT"
			if typestr == "t_rtmat":
				etype = "PT_MATERIAL"
		self.etype = etype

	def __str__(self):
		ret = self.ctype
		if self.pointer:
			ret = ret + " *"
		ret = ret + self.csufix
		return (ret)

	def __repr__(self):
		return (self.__str__())

	def __int__(self):
		if self.pointer:
			return 8
		return self.size * self.e_len

	def mkcvar(self, name, atab = 6, btab = 1):
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

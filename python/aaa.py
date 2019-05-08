# -*- coding: utf-8 -*-

def Abs(x):
	if not isinstance(x,(int,float)):
		raise TypeError('Bad operande type')
	if x>=0:
		return x
	else:
		return -x

#Fabio Tadashi Kaneiwa Kubo 145979

class ControleCombustivel(object):
	def __init__(self, data, volume, kms, vPorKm):
		self.data = data
		self.volume = volume
		self.kms = kms
		self.kmPorVolume = vPorKm

list = []

def anota(data, volume, kms):
	list.append(ControleCombustivel(data, volume, kms, kms/volume))
	list.sort(key=lambda x: x.kmPorVolume)

def consMin():
	return list[0].kmPorVolume, list[0].data

def consMax():
	return list[len(list) - 1].kmPorVolume, list[len(list) -1].data

def consMed():
	totalVolume = 0;
	totalKm = 0;
	for y in list:
		totalVolume += y.volume
		totalKm += y.kms;
	return totalKm/totalVolume

def kmMed():
	totalKm = 0;
	for y in list:
		totalKm += y.kms
	return totalKm/len(list)


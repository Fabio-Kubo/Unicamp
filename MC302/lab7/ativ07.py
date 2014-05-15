#Fabio Tadashi Kaneiwa Kubo 145979

class ControleCombustivel(object):
	def __init__(self, data, volume, kms, vPorKm):
		self.data = data
		self.volume = volume
		self.kms = kms
		self.kmPorVolume = vPorKm

controlesCombustiveis = []

def anota(data, volume, kms):
	controlesCombustiveis.append(ControleCombustivel(data, volume, kms, kms/volume))
	controlesCombustiveis.sort(key=lambda x: x.kmPorVolume)

def consMin():
	return controlesCombustiveis[0].kmPorVolume, controlesCombustiveis[0].data

def consMax():
	return controlesCombustiveis[len(controlesCombustiveis) - 1].kmPorVolume, controlesCombustiveis[len(controlesCombustiveis) -1].data

def consMed():
	totalVolume = 0;
	totalKm = 0;
	for y in controlesCombustiveis:
		totalVolume += y.volume
		totalKm += y.kms;
	return totalKm/totalVolume

def kmMed():
	totalKm = 0;
	for y in controlesCombustiveis:
		totalKm += y.kms
	return totalKm/len(controlesCombustiveis)


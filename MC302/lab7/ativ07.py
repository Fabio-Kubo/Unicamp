#Fabio Tadashi Kaneiwa Kubo 145979

class ControleCombustivel(object):

	#Construtor
	def __init__(self, data, volume, kms, vPorKm):
		self.data = data
		self.volume = volume
		self.kms = kms
		self.kmPorVolume = vPorKm

controlesCombustiveis = []

#Metodo que adiciona um controleCombustivel e ordena de acordo com o KmPorVolume
def anota(data, volume, kms):
	controlesCombustiveis.append(ControleCombustivel(data, volume, kms, kms/volume))
	controlesCombustiveis.sort(key=lambda x: x.kmPorVolume)

#Metodo que retorna o valor do consumo minimo (km/litro) e a data em que ocorre
def consMin():
	return controlesCombustiveis[0].kmPorVolume, controlesCombustiveis[0].data

#Metodo que retorna ovalor do consumo maximo (km/litro) e a data em que ocorre
def consMax():
	return controlesCombustiveis[len(controlesCombustiveis) - 1].kmPorVolume, controlesCombustiveis[len(controlesCombustiveis) -1].data

#Metodo que retorna o consumo medio
def consMed():
	
	#executa a soma de todos os valores de km/Volume
	return sum(ControleCombustivel.kmPorVolume for ControleCombustivel in controlesCombustiveis)/len(controlesCombustiveis)

#Metodo que retorna o valor da quilometragem media dos abastecimentos registrados
def kmMed():
	totalKm = 0;
	for y in controlesCombustiveis:
		totalKm += y.kms
	return totalKm/len(controlesCombustiveis)


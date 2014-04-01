package prodPlan;

import java.util.LinkedList;
import java.util.List;

public class ParteComposta extends Parte {

	private List<Item> itens;

	public ParteComposta(int cod, String nome, String descricao, float valor) {
		super(cod, nome, descricao, valor);
		itens = new LinkedList<Item>();
	}

	private Boolean existeParte(Parte parte) {

		for (Item item : this.itens) {
			if (item.parte.cod == parte.cod)
				return true;
		}
		return false;
	}

	public List<Item> listaDeItens() {

		return this.itens;
	}

	public void agregaItem(Parte parte, int quantidade) throws Exception {

		if (parte == null)
			throw new Exception("A parte não pode ser nula.");

		if (existeParte(parte))
			throw new Exception("A parte já foi adicionada.");

		if (quantidade == 0)
			throw new Exception("Quantidade não deve ser nula.");
		
		itens.add(new Item(parte, quantidade));
	}

	public float calculaValor() {
		
		float soma = this.valor;
		for (Item item : this.itens) {
			soma += item.calculaValor();
		}
		return soma;
	}

	public String toString() {

		return super.toString();
	}
}

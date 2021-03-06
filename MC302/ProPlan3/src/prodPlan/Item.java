package prodPlan;

public class Item {

	protected Parte parte;
	protected int quantidade;

	public Item(Parte parte, int quantidade) {

		this.parte = parte;
		this.quantidade = quantidade;
	}

	public float calculaValor() {
		return this.parte.calculaValor() * this.quantidade;
	}

	public String toString() {
		StringBuilder stb = new StringBuilder();
		stb.append("cod:");
		stb.append(this.parte.cod);
		stb.append(" nome:");
		stb.append(this.parte.nome);
		stb.append(" quantidade:");
		stb.append(this.quantidade);
		stb.append(" valor unitário:");
		stb.append(this.parte.valor);
		stb.append(" valor:");
		stb.append(this.calculaValor());

		return stb.toString();
	}

}

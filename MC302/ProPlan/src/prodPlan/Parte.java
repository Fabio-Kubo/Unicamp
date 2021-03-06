package prodPlan;

public abstract class Parte {

	protected int cod;
	protected String nome;
	protected String descricao;
	protected float valor;

	public Parte(int cod, String nome, String descricao, float valor) {

		this.cod = cod;
		this.nome = nome;
		this.descricao = descricao;
		this.valor = valor;
	}

	public float calculaValor() {

		return this.valor;
	}

	public String toString() {

		StringBuilder stb = new StringBuilder();
		stb.append("codigo:");
		stb.append(this.cod);
		stb.append(" nome:");
		stb.append(this.nome);
		stb.append(" descrição:");
		stb.append(this.descricao);
		stb.append(" valor:");
		stb.append(this.valor);

		return stb.toString();
	}

}

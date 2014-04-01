package prodPlan;

public class Parafuso extends Parte {

	protected float comprimento;
	protected float diametro;

	public Parafuso(int cod, String nome, String descricao, float valor,
			float comprimento, float diametro) {

		super(cod, nome, descricao, valor);
		this.comprimento = comprimento;
		this.diametro = diametro;
	}

	public String toString() {

		StringBuilder stb = new StringBuilder();
		stb.append(super.toString());
		stb.append(" comprimento:");
		stb.append(this.comprimento);
		stb.append(" diametro:");
		stb.append(this.diametro);

		return stb.toString();
	}

}

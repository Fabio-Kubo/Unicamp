package prodPlan;

public class Motor extends Parte {

	protected float potencia;
	protected float corrente;
	protected int rpm;

	public Motor(int cod, String nome, String descricao, float valor,
			float potencia, float corrente, int rpm) {

		super(cod, nome, descricao, valor);
		this.potencia = potencia;
		this.corrente = corrente;
		this.rpm = rpm;
	}

	public String toString() {

		StringBuilder stb = new StringBuilder();
		stb.append(super.toString());
		stb.append(" potencia:");
		stb.append(this.potencia);
		stb.append(" corrente:");
		stb.append(this.corrente);
		stb.append(" rpm:");
		stb.append(this.rpm);
		
		return stb.toString();
	}

}

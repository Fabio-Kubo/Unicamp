package prodPlan;

import xserial.*;

public class Motor extends Parte {

	protected float potencia;
	protected float corrente;
	protected int rpm;

	public Motor() {

	}

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

	@Override
	public void setObject(XSerial obj) {
		// TODO Auto-generated method stub

	}

	@Override
	public void setAttrib(String name, String value) {

		super.setAttrib(name, value);
		
		if (name.equals("potencia")) {
			this.potencia = Float.parseFloat(value);
		} else if (name.equals("corrente")) {
			this.corrente = Float.parseFloat(value);
		} else if (name.equals("rpm")) {
			this.rpm = Integer.parseInt(value);
		}

	}

	@Override
	public void setText(char[] chars, int start, int length) {
		// TODO Auto-generated method stub

	}

}

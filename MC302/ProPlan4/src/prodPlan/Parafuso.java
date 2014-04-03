package prodPlan;
import xserial.*;

public class Parafuso extends Parte implements XSerial{

	protected float comprimento;
	protected float diametro;
	
	public Parafuso(){
		
	}

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

	@Override
	public void setObject(XSerial obj) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setAttrib(String name, String value) {
		
		super.setAttrib(name, value);
		
		switch (name) {
			case "comprimento" :
				this.comprimento = Float.parseFloat(value);
				break;
			case "diametro" :
				this.diametro = Float.parseFloat(value);
				break;
		}
		
	}

	@Override
	public void setText(char[] chars, int start, int length) {
		// TODO Auto-generated method stub
		
	}

}

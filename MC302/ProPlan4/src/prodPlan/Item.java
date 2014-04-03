package prodPlan;
import xserial.*;

public class Item implements XSerial {

	protected Parte parte;
	protected int quantidade;

	public Item() {

	}

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

	@Override
	public void setObject(XSerial obj) {

		if (obj instanceof Parte)
			this.parte = (Parte) obj;
	}

	@Override
	public void setAttrib(String name, String value) {

		if (name.equals("quantidade")) {
			this.quantidade = Integer.parseInt(value);
		}
	}

	@Override
	public void setText(char[] chars, int start, int length) {
		// TODO Auto-generated method stub

	}

}

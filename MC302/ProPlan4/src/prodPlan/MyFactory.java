package prodPlan;

import xserial.*;

public class MyFactory implements XFactory {

	public MyFactory() {

	}

	@Override
	public XSerial makeObject(String name, XSerial upperObj) {

		switch(name){
			
			case "item" : return new Item();
			case "parafuso": return new Parafuso();
			case "motor" : return new Motor();
			case "parteComposta": return new ParteComposta();
			case "parteEspecifica": return new ParteEspecifica();
			case "caracteristica": return new Caracteristica();
			case "lista": return new Lista();
			default: return null;
		}
	}

}

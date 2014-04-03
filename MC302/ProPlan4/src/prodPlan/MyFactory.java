package prodPlan;

import xserial.*;

public class MyFactory implements XFactory {

	public MyFactory() {

	}

	@Override
	public XSerial makeObject(String name, XSerial upperObj) {

		if (name.equals("item")) {
			return new Item();
		} else if (name.equals("parafuso")) {
			return new Parafuso();
		} else if (name.equals("motor")) {
			return new Motor();
		} else if (name.equals("parteComposta")) {
			return new ParteComposta();
		} else if (name.equals("parteEspecifica")) {
			return new ParteEspecifica();
		} else if (name.equals("caracteristica")) {
			return new Caracteristica();
		} else if (name.equals("lista")) {
			return new Lista();
		} else {
			return null;
		}

	}

}

package xserial;

/**
 * Esta interface define o método makeObject() usado para a criação dos
 * objetos à medida em que é feito o processamento do documento XML pelo
 * objeto XParser.
 *
 */

public interface XFactory {
	
	public XSerial makeObject(String name, XSerial upperObj);

}

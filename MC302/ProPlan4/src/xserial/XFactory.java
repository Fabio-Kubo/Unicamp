package xserial;

/**
 * Esta interface define o m�todo makeObject() usado para a cria��o dos
 * objetos � medida em que � feito o processamento do documento XML pelo
 * objeto XParser.
 *
 */

public interface XFactory {
	
	public XSerial makeObject(String name, XSerial upperObj);

}

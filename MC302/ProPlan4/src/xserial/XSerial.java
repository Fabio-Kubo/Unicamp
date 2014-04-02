package xserial;

/**
 * Esta interface define os métodos a ser implementados pelas classes dos objetos
 * construídos durante o processamento do documento XML.
 *
 */

public interface XSerial {
	
	/**
	 * Associa resultante de uma 'tag filha' a este objeto.
	 * @param obj
	 */
	public void setObject(XSerial obj);
	
	/**
	 * Associa um atributo do doc. xml a este objeto.
	 * @param name
	 * @param value
	 */
	public void setAttrib(String name, String value);
	
	/**
	 * Associa um texto do xml a este objeto.
	 * @param chars
	 * @param start
	 * @param length
	 */
	public void setText(char[] chars, int start, int length);

}

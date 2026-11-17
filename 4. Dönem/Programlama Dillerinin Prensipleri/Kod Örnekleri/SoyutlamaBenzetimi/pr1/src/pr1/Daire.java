package pr1;

public class Daire extends Sekil{
	private double yaricap;
	
	public Daire(String renk, double yaricap) {
		super(renk);
		this.yaricap = yaricap;
	}
	@Override
	public double alan() {
		return Math.PI * yaricap * yaricap;
	}
	@Override
	public double cevre() {
		return 2 * Math.PI * yaricap;
	}
	

}

package pr1;

public class Kare extends Sekil{
	private double kenar;
	public Kare(String renk, double kenar) {
		super(renk);
		this.kenar = kenar;
	}
	@Override
	public double alan() {
		return Math.pow(kenar, 2);
	}
	@Override
	public double cevre() {
		return 4 * kenar;
	}
}

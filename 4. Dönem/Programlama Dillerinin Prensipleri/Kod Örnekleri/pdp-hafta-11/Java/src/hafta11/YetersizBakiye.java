package hafta11;

import java.io.IOException;

public class YetersizBakiye extends IOException {
	
	private String mesaj;
	public YetersizBakiye() {
		mesaj = "Hesapta yeterli bakiye yok";
	}
	public YetersizBakiye(String mesaj) {
		this.mesaj = mesaj;
	}
	@Override
	public String getMessage() {
		return mesaj;
	}
	
}

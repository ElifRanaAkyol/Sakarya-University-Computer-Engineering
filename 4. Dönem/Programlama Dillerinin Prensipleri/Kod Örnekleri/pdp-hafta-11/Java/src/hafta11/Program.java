package hafta11;

public class Program {

	public static void main(String[] args) {
		Hesap hesap = new Hesap();
		try {
			hesap.paraYatir(100);
			System.out.println(hesap);
			hesap.paraCek(50);
			System.out.println(hesap);
			hesap.paraCek(60); // Bu satır hata verecek
		} catch (IllegalArgumentException | YetersizBakiye e) {
			System.out.println("Hata: " + e.getMessage());
		}
		finally { //ne olursa olsun ekrana bir çıktı gönderir bakiyeyi veir
			System.out.println(hesap);
		}
	}
}

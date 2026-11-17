#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

// süreç takibi ve alarm sayımı degiskenleri
pid_t child_pid;
int alarm_count = 0;

//çocuk süreci için SIGINT sinyal işleyicisi
void child_sigint_handler(int sig) {
    // sinyal alındığında bildirlir
    printf("\nÇocuk: SIGINT alındı ancak devam ediliyor...\n");
    fflush(stdout);
}

// çocuk süreci için SIGCONT sinyal işleyicisi
void child_sigcont_handler(int sig) {
    // süreç kaldığı yerden devam ettiğinde tetiklenir
    printf("Çocuk: İşlem yeniden başlatıldı\n");
    fflush(stdout);
}

 //3 saniyede bir tetiklenir
 
void parent_sigalrm_handler(int sig) {
    alarm_count++;
    
    // ilk 3 alarm döngüsünde durdurma- devam ettirme mekanizması çalışır
    if (alarm_count <= 3) {
        printf("Ebeveyn: Çocuk durduruluyor...\n");
        fflush(stdout);
        // çocuk sürece durdurma sinyali gönderilir
        kill(child_pid, SIGSTOP);
        
        // 2 saniye beklenir
        sleep(2);
        
        printf("Ebeveyn: Çocuk devam ediyor...\n");
        fflush(stdout);
        // çocuk süreci kaldığı yerden devam eder SIGCONT gönderilir
        kill(child_pid, SIGCONT);
        
        //  bir sonraki alarmı 3 saniye sonrasına tekrar kuruyoruz
        alarm(3);
    }
}

int main() {
    // fork() ile yeni bir alt süreç (child) oluşturuluyor
    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork hatasi");
        return 1;
    } 
    else if (child_pid == 0) {
        
        // sinyal işleyicilerinin kaydedilir
        signal(SIGINT, child_sigint_handler);
        signal(SIGCONT, child_sigcont_handler);

        int counter = 0;
        // sonsuz döngüde her saniye sayacı ekrana yazdırır
        while (1) {
            printf("Çocuk sayacı: %d\n", counter++);
            fflush(stdout); // çıktının terminale anlık düşmesini sağlar
            sleep(1);
        }
    } 
    else {

        // ebeveyn için alarm sinyali işleyicisini kaydediyoruz
        signal(SIGALRM, parent_sigalrm_handler);
        
        // ilk alarmı 3 saniye sonrasına kuruyoruz
        alarm(3);

        // ebeveyn süreç, alarm döngüleri  bitene kadar bekler
        while (alarm_count < 3) {
            pause(); // bir sinyal gelene kadar ebeveyn süreci uyutur
        }

        // yaklaşık 10 saniye simülasyonu sonu adımları
        sleep(1); 
        printf("Ebeveyn: SIGINT gönderiliyor...\n");
        fflush(stdout);
        
        // çocuğa SIGINT gönderilir 
        kill(child_pid, SIGINT);
        sleep(1); 
        // çocuk süreci kalıcı olarak sonlandırıyoruz
        kill(child_pid, SIGKILL);
        
        //yetim süreç kalmaması için çocuğun tamamen kapanmasını bekliyoruz
        wait(NULL);
        
        printf("Ebeveyn: Çocuk sonlandırıldı.\n");
        fflush(stdout);
    }

    return 0;
}
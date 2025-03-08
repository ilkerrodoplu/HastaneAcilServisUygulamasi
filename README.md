# Hastane Acil Servis Uygulamasi
## ÖZELLİKLER
Bu proje, acil servislerde hasta kayıtlarını yönetmek amacıyla geliştirilen C diliyle yazılmış bir programıdır. 

## NEREDE KULLANILIR ?
- Yeni hasta kaydı oluşturma
- Hastaları kimin daha acil olduğuna göre sıralamaktadır
- Reçete numarası oluşturma

## HASTA ÖNCELİK SIRALANDIRMASI

Hastalar, aşağıdaki kriterlere göre önceliklendirilir:

- Ateş değeri 36-38°C arasında değilse

- Tansiyon değeri normal aralıkta değilse (büyük tansiyon 90-140 mmHg, küçük tansiyon 60-90 mmHg)

- Manuel olarak kullanıcı tarafından 1 (en düşük) ile 5 (en yüksek) arasında belirlenebilir

## HASTA LİSTELENME FORMATI
Hastalar listelenmek istenildiği zaman HL7 formatında sıralanmaktadır.
HL7 formantı aşağıdaki gibidir:
> PID|Sıra No||Belge No||Kimlik No||İsim^Soyisim||YYYYMMDD||Cinsiyet||Adres Bilgileri||Telefon No|

## NASIL ÇALIŞTIRILIR?
İnternet üzerinden uygulamaya gerek olmadan çalışan bir derleyici: [Online C Compiler](https://www.onlinegdb.com/online_c_compiler)

Windows bilgisayarda çalışması için: [DevC++(Direk indirme sayfasına atar)](https://sourceforge.net/projects/dev-cpp/files/Binaries/Dev-C%2B%2B%204.9.9.2/devcpp-4.9.9.2_setup.exe/download) 

Tüm bilgisayarlarda çalışması için: [Visual Studio](https://code.visualstudio.com/Download)

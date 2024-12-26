# armanbahadir-inp103
---

# Titreşim Algılama ve Uyarı Sistemi

Bu proje, her türlü titreşim algılandığında bir **buzzer**, **LED** ve **titreşim motoru** kullanarak kullanıcıyı uyaran bir sistemdir. Başlangıçta, **SW200D model eğim sensörü** kullanılmıştır, ancak devre pratikte **KY-002 model titreşim sensörü** ile çalışacak şekilde revize edilecektir.

## Proje Özeti

Bu proje, titreşim algılandığında çeşitli uyarılar veren bir sistemin tasarımını ve kodlamasını içerir. Titreşim sensörü, algıladığı titreşimleri mikrokontrolöre iletir ve sistem, uygun bir şekilde uyarı verir. Devrede bir **LED**, **buzzer** ve **titreşim motoru** bulunur. Bu bileşenler kullanıcıya görsel ve sesli uyarılar sağlar.

### Kullanılan Bileşenler

- **Arduino Uno** (veya uyumlu başka bir mikrodenetleyici)
- **KY-002 Titreşim Sensörü** (SW200D yerine pratikte kullanılacak)
- **LED** (görsel uyarı için)
- **Buzzer** (sesli uyarı için)
- **Titreşim Motoru** (titreşimli uyarı için)
- **Bağlantı kabloları ve dirençler**

### Devre Şeması

Devre, aşağıdaki temel bileşenleri içerir:

- **Titreşim Sensörü (KY-002)**: Titreşim algıladığında dijital sinyal gönderir.
- **LED**: Titreşim algılandığında yanar.
- **Buzzer**: Sesli bir uyarı verir.
- **Titreşim Motoru**: Fiziksel bir titreşim hissi verir.

**Not**: Proje başlangıçta SW200D eğim sensörü ile yapılmış ancak KY-002 titreşim sensörüne geçiş yapılacaktır. Bu değişiklik devrede bazı bağlantı ve kod düzenlemelerini gerektirecektir.

## Kurulum ve Bağlantılar

1. **Titreşim Sensörü (KY-002)**:
   - VCC pinini 5V'ye bağlayın.
   - GND pinini GND'ye bağlayın.
   - OUT pinini Arduino'nun dijital bir pinine (örneğin, D2) bağlayın.

2. **LED**:
   - Bir bacağınızı GND'ye, diğer bacağını ise 220Ω direnç üzerinden Arduino'nun dijital pinlerinden birine (örneğin, D3) bağlayın.

3. **Buzzer**:
   - Bir bacağını GND'ye, diğer bacağını Arduino'nun dijital pinlerinden birine (örneğin, D4) bağlayın.

4. **Titreşim Motoru**:
   - Motoru uygun şekilde güç kaynağına ve Arduino'ya bağlayın. (Motorun çalışma voltajına dikkat edin)

## Yazılım

Aşağıdaki Arduino kodu, titreşim algılandığında LED'i yakar, buzzeri çalar ve titreşim motorunu çalıştırır:

```cpp
// Pin tanımlamaları
const int sensorPin = 2;    // KY-002 Titreşim Sensörü
const int ledPin = 3;       // LED pin
const int buzzerPin = 4;    // Buzzer pin
const int motorPin = 5;     // Titreşim motoru pin

void setup() {
  // Pin modlarını ayarla
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  
  // Seri iletişimi başlat
  Serial.begin(9600);
}

void loop() {
  int sensorState = digitalRead(sensorPin);  // Sensörden veri oku

  // Titreşim algılandıysa
  if (sensorState == HIGH) {
    digitalWrite(ledPin, HIGH);     // LED'i yak
    digitalWrite(buzzerPin, HIGH);  // Buzzer'ı çal
    digitalWrite(motorPin, HIGH);   // Titreşim motorunu çalıştır
    
    // 1 saniye uyarı ver
    delay(1000);

    // Uyarıları kapat
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(motorPin, LOW);
  }

  delay(100);  // Küçük bir gecikme
}
```

### Kod Açıklaması

- **sensorPin**: Titreşim sensöründen gelen veriyi okur.
- **ledPin**: Titreşim algılandığında LED'in yanmasını sağlar.
- **buzzerPin**: Buzzer'ı çalıştırarak sesli uyarı verir.
- **motorPin**: Titreşim motorunu çalıştırarak fiziksel bir uyarı verir.

### Sensör Değişikliği Notu

Başlangıçta SW200D eğim sensörü kullanılmıştır. Ancak devrede KY-002 model titreşim sensörüne geçiş yapılacaktır. Bu sensör daha hassas bir titreşim algılayıcıdır ve dijital bir çıkış verir. SW200D yerine KY-002 kullanmak, kodda birkaç küçük değişiklik gerektirir, ancak genel çalışma prensibi aynıdır.

## Kullanıcıya Yönelik Notlar

- **Sensör Montajı**: KY-002 titreşim sensörü, titreşimleri algılayarak dijital bir sinyal gönderir. Eğer sensör doğru şekilde bağlanmazsa, sistem düzgün çalışmayabilir.
- **Titreşim Motoru Gücü**: Titreşim motoru genellikle daha fazla güç gerektirir. Bu nedenle, motorun doğru voltajda çalıştığından emin olun ve gerekirse bir harici güç kaynağı kullanın.

## Geliştirme Fikirleri

- **Farklı Sensörler**: Bu projede kullanılan sensör, titreşim algılayabilen başka sensörlerle değiştirilebilir.
- **Veri İletişimi**: Titreşim algılandıktan sonra verilerin bir ekran veya uzaktan bir cihazla iletişimi sağlanabilir.
- **Daha Fazla Uyarı Mekanizması**: Örneğin, bir LCD ekran eklenerek titreşimle ilgili daha fazla bilgi görüntülenebilir.

## Katkılar

Bu proje açık kaynaklıdır ve katkılarınızı beklemektedir. Kodunuzu veya devrenizi geliştirmek için bir pull request gönderebilirsiniz.

---

Bu README dosyası, projenin genel hatlarını ve nasıl çalıştığını açıklar. Ayrıca, devrede yapılan sensör değişikliği hakkında bilgi verilir.

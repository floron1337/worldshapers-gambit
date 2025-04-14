# Worldshaper's Gambit

**Worldshaper’s Gambit** este un joc de strategie și decizie în care jucătorul ia rolul unui lider global, luând decizii critice care afectează soarta planetei. Prin intermediul unui sistem de cărți generate dinamic, jucătorul trebuie să gestioneze diverse aspecte precum finanțele, opinia publică, puterea și industria, în timp ce se confruntă cu facțiuni rivale și încercă să mențină controlul. Cu multiple finaluri posibile și un gameplay accesibil, jocul oferă o experiență captivantă, plină de provocări și alegeri morale complexe.

## Descriere Generală

Într-un viitor tensionat și instabil, jucătorul conduce **Ordinul Planetar**, partidul dominant al Terrei. Printr-un sistem inovator de **cărți generate dinamic**, acesta trebuie să gestioneze:

- **Finanțele**
- **Opinia publică**
- **Puterea politică**
- **Industria**

În același timp, jucătorul este nevoit să confrunte și să manipuleze diverse **facțiuni rivale**, fiecare cu ideologii, scopuri și metode proprii. Deciziile au consecințe directe asupra evoluției campaniei și pot duce la multiple finaluri posibile, unele triumfătoare, altele dezastruoase.

---

## Facțiuni

### 🔷 Ordinul Planetar (The Planetary Order)
- **Rol:** Partidul conducător al planetei, condus de jucător.
- **Scop:** Menținerea puterii cât mai mult timp posibil și eliminarea/recrutarea facțiunilor rivale.
- **Ideologie:**
  - Globalism autoritar
  - Militarism
  - Turbo-capitalism
  - Anti-naționalism
  - Control strict asupra vieții personale

---

### ⚫ Eclipsa Puterii (Power Eclipse)
- **Rol:** Principalul grup revoluționar.
- **Scop:** Răsturnarea conducerii și instaurarea unei societăți egale, fără lideri.
- **Strategie:** Poate fi asuprită sau manipulată pentru a evita o revoltă majoră.
- **Ideologie:**
  - Anarho-egalitarism
  - Anticapitalism
  - Antimilitarism
  - Descentralizare

---

### 👑 Monarhia Omniterra (Omniterra Monarchy)
- **Rol:** Adversar politic direct.
- **Scop:** Restaurația regalității prin impunerea unui rege absolut.
- **Strategie:** Principalul inamic politic, necesită alocarea resurselor strategice pentru contracarare.
- **Ideologie:**
  - Monarhie absolută
  - Cultul personalității
  - Tehno-feudalism
  - Sclavie modernă
  - Glorificarea trecutului

---

### ☦️ Legiunea Credinței Oarbe (The Legion of Blind Faith)
- **Rol:** Facțiune religioasă radicală.
- **Scop:** Îndeplinirea unei profeții misterioase și dominarea spirituală a planetei.
- **Strategie:** Operează prin celule izolate, specializate în infiltrare, asasinate și teroare.
- **Ideologie:**
  - Fanatism religios
  - Auto-distrugere în numele profeției

---

### 🕊️ Cultul Autodeterminării (The Cult of Self Determination)
- **Rol:** Mișcare radicală tradiționalistă.
- **Scop:** Dizolvarea Ordinului Planetar și reîntoarcerea la valorile trecutului.
- **Ideologie:**
  - Ultranationalism
  - Tradiționalism extremist
  - Glorificarea trecutului
  - Credința în superioritatea rasială

---

## Caracteristici cheie

- 🎴 **Sistem de decizii bazat pe cărți generate dinamic**
- 🔄 **Gameplay cu finaluri multiple, dependente de alegerile morale**
- 🌍 **Gestionare complexă a resurselor și a influenței globale**
- 🧠 **Conflict ideologic profund și provocări politice reale**
- 🎯 **Accesibil, dar profund strategic**

---

## Obiectivul jucătorului

Rămâi la conducerea planetei prin orice mijloace: diplomație, propagandă, represiune sau manipulare. Înfruntă haosul și modelează lumea după viziunea ta.

### Important!

Aveți voie cu cod generat de modele de limbaj la care nu ați contribuit semnificativ doar în folder-ul `generated`.
Codul generat pus "ca să fie"/pe care nu îl înțelegeți se punctează doar pentru puncte bonus, doar în contextul
în care oferă funcționalități ajutătoare și doar dacă are sens.

O cerință nu se consideră îndeplinită dacă este realizată doar prin cod generat.

- **Fără cod de umplutură/fără sens!**
- **Fără copy-paste!**
- **Fără variabile globale!**
- **Fără atribute publice!**

### Tema 0

- [x] Nume proiect (poate fi schimbat ulterior)
- [x] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Tema 1

#### Cerințe
- [x] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi; moștenirile nu se iau în considerare aici
- [x] constructori de inițializare cu parametri pentru fiecare clasă
- [x] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor
<!-- - [x] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
<!-- - [x] pentru o altă clasă: toate cele 5 funcții membru speciale -->
- [x] `operator<<` pentru **toate** clasele pentru afișare (`std::ostream`) folosind compunere de apeluri cu `operator<<`
- [x] cât mai multe `const` (unde este cazul) și funcții `private`
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități netriviale specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
  - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [x] scenariu de utilizare **cu sens** a claselor definite:
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [x] minim 50-55% din codul propriu să fie C++, `.gitattributes` configurat corect
- [x] tag de `git`: de exemplu `v0.1`
- [x] serviciu de integrare continuă (CI) cu **toate bifele**; exemplu: GitHub Actions

## Tema 2

#### Cerințe
- [ ] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri:
  - minim o clasă de bază și **3 clase derivate** din aceeași ierarhie
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [ ] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (i.e. nu simple citiri/afișări sau preluate din biblioteci i.e. draw/update/render)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
    - afișare virtuală, interfață non-virtuală
  - [ ] apelarea constructorului din clasa de bază din constructori din derivate
  - [ ] clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază
    - [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
    - [ ] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
    - [ ] smart pointers (recomandat, opțional)
- [ ] excepții
  - [ ] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice distincte
    - clasele de excepții trebuie să trateze categorii de erori distincte (exemplu de erori echivalente: citire fișiere cu diverse extensii)
  - [ ] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
  - această ierarhie va fi complet independentă de ierarhia cu funcții virtuale
- [ ] funcții și atribute `static`
- [ ] STL
- [ ] cât mai multe `const`
- [ ] funcții *de nivel înalt*, de eliminat cât mai mulți getters/setters/funcții low-level
- [ ] minim 75-80% din codul propriu să fie C++
- [ ] la sfârșit: commit separat cu adăugarea unei noi clase derivate fără a modifica restul codului, **pe lângă cele 3 derivate deja adăugate** din aceeași ierarhie
  - noua derivată nu poate fi una existentă care a fost ștearsă și adăugată din nou
  - noua derivată va fi integrată în codul existent (adică va fi folosită, nu adăugată doar ca să fie)
- [ ] tag de `git` pe commit cu **toate bifele**: de exemplu `v0.2`

## Tema 3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
- [ ] minim 85% din codul propriu să fie C++
<!-- - [ ] o specializare pe funcție/clasă șablon -->
- [ ] tag de `git` pe commit cu **toate bifele**: de exemplu `v0.3` sau `v1.0`

## Instrucțiuni de compilare

Proiectul este configurat cu CMake.

Instrucțiuni pentru terminal:

1. Pasul de configurare
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
# sau ./scripts/cmake.sh configure
```

Sau pe Windows cu GCC:
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
# sau ./scripts/cmake.sh configure -g Ninja
```

La acest pas putem cere să generăm fișiere de proiect pentru diverse medii de lucru.


2. Pasul de compilare
```sh
cmake --build build --config Debug --parallel 6
# sau ./scripts/cmake.sh build
```

Cu opțiunea `parallel` specificăm numărul de fișiere compilate în paralel.


3. Pasul de instalare (opțional)
```sh
cmake --install build --config Debug --prefix install_dir
# sau ./scripts/cmake.sh install
```

Vezi și [`scripts/cmake.sh`](scripts/cmake.sh).

Observație: folderele `build/` și `install_dir/` sunt adăugate în fișierul `.gitignore` deoarece
conțin fișiere generate și nu ne ajută să le versionăm.


## Resurse

- adăugați trimiteri către resursele externe care v-au ajutat sau pe care le-ați folosit

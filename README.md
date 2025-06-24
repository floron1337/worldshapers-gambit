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
### Artă și Grafică
- [Bratu Rareș-Tiberiu](https://www.linkedin.com/in/rare%C8%99-tiberiu-bratu-86b70b339/)
### Inspirație Gameplay și Estetică
- [Reigns](https://store.steampowered.com/app/474750/Reigns/)
- [1984 - George Orwell](https://en.wikipedia.org/wiki/Nineteen_Eighty-Four)
- [Papers, Please](https://store.steampowered.com/app/239030/Papers_Please/)

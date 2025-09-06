# Inlämningsuppgift 2 – Klasser i C++

## Beskrivning
Denna uppgift demonstrerar grunderna i C++-klasser:
* Namnrymder
* Enumerationsklasser (`enum class`)
* Konstruktorer med defaultargument
* Default-destruktor och raderade copy/move-konstruktorer
* Get- och set-metoder
* Utskrift med `print(std::ostream&)`

All kod är strukturerad enligt kursens riktlinjer med `inc/` för headerfiler och `src/` för källkod.

## Innehåll
- `inc/car.h` – deklaration av klassen `vehicle::Car` och enum `TransmissionType`.
- `src/car.cpp` – implementation av klassen `Car`.
- `src/main.cpp` – testprogram för uppgifterna 1–5.
- `Makefile` – kompilering, körning och städning.

## Uppgifter
### G-nivå
1. Skapa projektstruktur och testutskrift.
2. Definiera enum `TransmissionType { Manual, Automatic }`.
3. Skapa klassen `Car` med privata attribut och metoder enligt uppgiften.
4. Testa med objekt `car1` (Volkswagen Golf, Gray, 2002), byt färg till blå och växellåda till automatisk.

### VG-nivå
5.
- Skapa tre bilar (`Volvo V70`, `BMW Z3`, `Skoda Octavia RS`).
- Lagra pekare till dessa i en `std::vector<Car*>`.
- Iterera och skriv ut bilarna.
- Ändra alla färger till röd och skriv ut igen.
- Skriv slutligen informationen till filen `cars.txt`.

## Kompilering och körning
Bygg och kör programmet direkt:
```bash
make

# Inlämning 1 – Vektorer i C++

## Beskrivning
I den här inlämningen har jag jobbat med vektorer i C++.  
Uppgifterna gick ut på att:
- Iterera genom vektorer på olika sätt (index, range-based for, iteratorer).
- Testa på standardfunktioner som `size()`, `empty()`, `push_back()` m.m.
- Skriva egna funktioner i en namespace `vector`, bl.a.:
  - `getLargestInt` – hitta största heltalet.
  - `sort<T>` – sortera en numerisk vektor (med `static_assert` för att stoppa icke-numeriska typer).
  - `getNextLargest<T>` – returnera det näst största distinkta värdet.

## Arbetssätt
Jag har skrivit själva uppgiftsdelarna själv, med stöd från kursmaterialet.  
Jag har också använt AI som förslag och inspiration, och ibland för att få förklaringar till olika lösningar.  
Testdelen (alla små “PASS/FAIL”-tester och kantfall) är till stor del genererad av AI, men jag har gått igenom koden och förstått hur den fungerar.  

Jag har även kikat på andra AI-lösningar som t.ex. använder `std::sort` rakt av eller mer avancerade mallar, men valde att hålla mig till kursens stil och C++17.

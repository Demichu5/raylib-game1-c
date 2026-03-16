# Raylib Game Engine Core (C)

Projekt autorskiego silnika graficznego 2D opartego na bibliotece **Raylib**. Skupia się na niskopoziomowym zarządzaniu zasobami, logice kafelkowej (Tilemap) oraz modularnej architekturze struktur danych.

## Kluczowe Funkcjonalności
* [cite_start]**Dynamiczna Obsługa Tilemap:** System wczytywania poziomów z zewnętrznych plików konfiguracyjnych.
* **Modularna Architektura Gracza:** Zastosowanie struktur o stałym rozmiarze do przechowywania statystyk, ekwipunku i stanu postaci (optymalizacja pod kątem zużycia pamięci).
* **Zarządzanie Kamerą:** Implementacja kamery 2D z płynnym śledzeniem celu i systemem statystyk w czasie rzeczywistym.
* **Resource Management:** Ścisła kontrola cyklu życia tekstur (ładowanie/zwalnianie VRAM).

## Aspekty Techniczne
* **Język:** C
* **Zależności:** Raylib
* **Główne struktury:** Wykorzystanie aliasów typów danych (u8, u16, f32) dla zwiększenia czytelności i przenośności kodu.

## Struktura Projektu
* `main.c` – pętla główna i inicjalizacja systemów.
* `player.c/h` – definicje struktur danych gracza (134 bajty na instancję).
* `default.h` – globalna konfiguracja, stałe i definicje typów.

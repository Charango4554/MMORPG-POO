#include <iostream>
#include <string>
#include <random>

class Personnage {
private:
    std::string _nom;
    int _points_de_vie;
    Arme* _arme;

public:
    Personnage(std::string nom, int points_de_vie) : _nom(nom), _points_de_vie(points_de_vie), _arme(nullptr) {}

    std::string nom() const { return _nom; }
    int points_de_vie() const { return _points_de_vie; }
    bool est_vivant() const { return _points_de_vie > 0; }
    void blesse(int pv) { _points_de_vie -= pv; }
    void donner_arme(Arme* arme) { _arme = arme; }
    bool a_une_arme() const { return _arme != nullptr; }
    int attaque() const {
        if (_arme == nullptr) {
            return 0;
        } else {
            return _arme->degat_aleatoire();
        }
    }
};

class Arme {
private:
    std::string _nom;
    int _degats_min;
    int _degats_max;

public:
    Arme(std::string nom, int degats_min, int degats_max) : _nom(nom), _degats_min(degats_min), _degats_max(degats_max) {}

    std::string nom() const { return _nom; }
    int degat_aleatoire() const {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(_degats_min, _degats_max);
        return dis(gen);
    }
};

class Arbitre {
private:
    Personnage* _p1;
    Personnage* _p2;

public:
    Arbitre(Personnage* p1, Personnage* p2) : _p1(p1), _p2(p2) {}

    Personnage* personnage1() const { return _p1; }
    Personnage* personnage2() const { return _p2; }

    void un_round(Personnage* attaquant, Personnage* defenseur) {
        int degats = attaquant->attaque();
        std::cout << attaquant->nom() << " attaque " << defenseur->nom() << " avec ";
        if (attaquant->a_une_arme()) {
            std::cout << "son " << attaquant->a_une_arme()->nom() << " ";
        } else {
            std::cout << "ses poings ";
        }
        std::cout << "et inflige " << degats << " dégâts." << std::endl;
        defenseur->blesse(degats);
    }

    void combat() {
        int round = 1;
        Personnage* attaquant = _p1;
        Personnage* defenseur = _p2;
        while (attaquant->est_vivant() && defenseur->est_vivant()) {
            std::cout << "Round " << round << std::endl;
            un_round(attaquant, defenseur);
            if (defenseur->est_vivant()) {
                std::swap(attaquant, defenseur);
                un_round(attaquant, defenseur);
            }
            round++;
            std::cout << std::endl;
        }
        std::cout << "Le combat est terminé !" << std::endl;
        if (_p1->est_vivant()) {
            std::cout << _

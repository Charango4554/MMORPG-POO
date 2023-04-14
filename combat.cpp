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
        PersonnageArme _p1;
        PersonnageArme _p2;
        int _round;
    
    public:
        Arbitre(PersonnageArme p1, PersonnageArme p2) : _p1(p1), _p2(p2), _round(1) {}
        
        PersonnageArme personnage1() const {
            return _p1;
        }
        
        PersonnageArme personnage2() const {
            return _p2;
        }
        
        void un_round() {
            PersonnageArme attaquant;
            PersonnageArme defenseur;
            
            // On alterne entre les deux personnages à chaque round
            if (_round % 2 == 1) {
                attaquant = _p1;
                defenseur = _p2;
            } else {
                attaquant = _p2;
                defenseur = _p1;
            }
            
            // L'attaquant frappe le défenseur
            int degats = attaquant.arme().degatAleatoire();
            defenseur.blesse(degats);
            
            // On affiche les détails de l'attaque
            cout << "Round " << _round << ":" << endl;
            cout << attaquant.nom() << " attaque " << defenseur.nom() << " avec " << attaquant.arme().nom() << " et inflige " << degats << " dégâts." << endl;
            cout << defenseur.nom() << " a maintenant " << defenseur.pointsDeVie() << " points de vie." << endl;
            
            // On incrémente le nombre de rounds
            _round++;
        }
        
        void combat() {
            // On commence par afficher les informations des personnages
            cout << "Combat entre " << _p1.nom() << " et " << _p2.nom() << " : " << endl;
            cout << _p1.nom() << " (" << _p1.pointsDeVie() << " PV) est armé de " << _p1.arme().nom() << " (" << _p1.arme().degatMin() << "-" << _p1.arme().degatMax() << " dégâts)." << endl;
            cout << _p2.nom() << " (" << _p2.pointsDeVie() << " PV) est armé de " << _p2.arme().nom() << " (" << _p2.arme().degatMin() << "-" << _p2.arme().degatMax() << " dégâts)." << endl;
            
            // On simule les rounds jusqu'à la fin du combat
            while (_p1.estVivant() && _p2.estVivant()) {
                un_round();
            }
            
            // On affiche le gagnant
            if (_p1.estVivant()) {
                cout << _p1.nom() << " remporte le combat !" << endl;
            } else {
                cout << _p2.nom() << " remporte le combat !" << endl;
            }
        }
};


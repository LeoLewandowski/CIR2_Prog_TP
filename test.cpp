#include <iostream>


template <typename _My_type, size_t _size> // type des éléments et taille de la matrice carrée
class My_square_matrix {
    std::array <My_vector<_My_type, _size>, _size > mat_;
public:
    const size_t size = _size;
    My_vector<_My_type, _size>& operator()(const size_t& i); /* retourne le ième élément de mat_
    */
    My_vector<_My_type, _size> operator*(My_vector<_My_type, _size>& v); //produit d'une matrice par un vecteur -> vecteur */
    My_square_matrix<_My_type, _size> operator*(My_square_matrix<_My_type, _size>& m); /*
    produit d'une matrice par une matrice -> matrice */
    template <typename My_type, size_t size>
    friend std::ostream& operator<<(std::ostream& os, const My_square_matrix<My_type, size>& v);
};

// j'ai fait ça pour définir l'operator* 

// operator *

template <typename _My_type, size_t _size>
My_vector<_My_type, _size> My_square_matrix<_My_type, _size>::operator*(My_vector<_My_type, _size>& v) {
//code à compléter
    My_vector<_My_type, _size> result;
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; i < _size; ++j) {
            result[i][j] = 0;
            for (size_t k = 0; k < _SIZE; ++k) {
                r[i][j] += mat_[i][k] * v(k)[j];
            }
        }
    }
    return v;
}
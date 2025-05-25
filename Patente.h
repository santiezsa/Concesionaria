#pragma once

class Patente
{
    public:
        Patente();

        Patente(const char* numeroPatente, const char* numeroChasis);

        /// Getters
        const char* getNumeroPatente();
        const char* getNumeroChasis();

        /// Setters
        void setNumeroPatente(const char* numeroPatente);
        void setNumeroChasis(const char* numeroChasis);

    private:
        char _numeroPatente[10];
        char _numeroChasis[10];
};



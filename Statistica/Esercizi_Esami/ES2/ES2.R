setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES2")

load("trazione.RData") # carico il data-set
str(dati)             # descrizione compatta delle colonne dei dati -> colonna algoritmo e tempo
head(dati)            # visualizzo le prime righe dei dati

nrow(dati)            # numero di osservazioni

# calcolo media e deviazione standard della trazione per i materiali di tipo B
mean(dati$trazione[dati$materiale == "B"])
sd(dati$trazione[dati$materiale == "B"])

# conto quante righe hanno materiale B e trazione >= 30
# ci deve essere la virgola al fonto, perchè dati$trazione è un vettore numerico
sum(dati$trazione[dati$materiale == "B"] >= 30)

# calcolo il 20% delle trazioni più alte per i materiali di tipo B
quantile(dati$trazione[dati$materiale == "B"], 0.8)

# Box plot dei dati
boxplot(trazione ~ materiale, 
        data = dati,
        main = "Contronto trazione materiale A e B",
        xlab = "Materiale",
        ylab = "Trazione")

# Bar plot dei dati
barplot(table(dati$materiale),
        main = "Numero di osservazioni per materiale",
        xlab = "Materiale",
        ylab = "Numero di osservazioni",
        col = c("lightblue", "lightgreen"))


#"Vuoi dare una risposta quantitativa alla domanda: i due materiali hanno la stessa performance?
#In altre parole, la resistenza media alla trazione è uguale per i due materiali? Per rispondere a questa domanda, calcoli:"
#Risposta: 
#un test di ipotesi per la differenza delle medie, per campioni indipendenti, con ipotesi nulla H₀: μₐ = μᵦ
# Campioni indipendenti: I dati provengono da due materiali diversi (non misure ripetute)


t.test(dati$trazione[dati$materiale == "A"], dati$trazione[dati$materiale == "B"], alternative = "two.sided", paired = FALSE)



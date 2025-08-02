setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES3")

load("sicurezza.RData")
str(dati)
head(dati)

table(dati$sicurezza) #frequenza di sicurezza presente e non presente
sum(is.na(dati))      #conto quante righe hanno dati mancanti

dati_puliti <- na.omit(dati) #rimuovo le righe con dati mancanti
#media e dev. standard dei veicoli con sicurezza
mean(dati$vel[dati$sicurezza == "presente"]) 
sd(dati$vel[dati$sicurezza == "presente"])

# velocità del 10% delle macchine più veloci
quantile(dati_puliti$vel, 0.9, na.rm = TRUE )  # na.rm -> escludo i valori mancanti

hist(dati$vel)

#Vuoi dare una risposta quantitativa alla domanda: più del 60% dei veicoli in strada ha dispositivi di sicurezza. 
#Per rispondere a questa domanda, esegui un test di ipotesi per..

#Richiede un test unilaterale (one-tailed) perché l'ipotesi è direzionale ("più del 60%")

# Show me the % with vehicle with and without security
prop.table(table(dati$sicurezza)) * 100  # percentuale di veicoli con e senza sicurezza

# Test binomale per vedere se più del 60% dei veicoli ha dispositivi di sicurezza
binom.test(80,115,p = 0.6, alternative = "greater")

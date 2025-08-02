setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES7")

load("prodotto.RData")
str(dati)
head(dati)

nrow(dati) # Numero righe
mean(dati$eta) # Età media  

table(dati$preferenza) # Numero "Attuale" e numero "Sperimentale"
proportions(table(dati$preferenza)) #Proporzione in percetuale tra attuale e sperimentale
proportions(table(dati$preferenza[dati$eta < 35])) #Proporzione in percetuale tra attuale e sperimentale tenendo conto età < 35

mean(dati$eta[dati$preferenza == "Sperimentale"]) #Eta media preferenza sperimentale

boxplot(eta ~ preferenza, data = dati) 

#Almeno il 50% dei dati preferisce sperimentale?
binom.test(sum(dati$preferenza == "Sperimentale"), nrow(dati), p = 0.5, alternative = "greater")

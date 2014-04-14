# Progetto di reti di telecomunicazione su MobileIPv6
### Autori: Leonardo Galteri & Sandro Mehic

## Cose che mobile node deve fare

* deve mantenere la Binding Update List mandata sia al HA che ai correspondent nodes
* Binding Update List e' definita in 11.1
* deve scegliere di usare home address o una delle CoA quando e' fuori casa per mandare i pacchetti
* deve usare la home address quando usa transport-level connections che sono state inizalizzate da casa
* puo' scegliere se usare home address o CoA ma l'implementazione non e' nella rfc
* non puo' usare la home address se comunica con local peer della home network ma e' fuori casa
* se usa la home address mentre e' away from home per mandare i pacchetti deve usare la route optimization o reverse tunelling
* deve mandare mobile prefix solicitation
* deve ricevere ed analizzare mobile prefix advertisement
* gestione dei key e dei nonce per messaggi di gestione
* gestione della sicurezza e autenticazione
* mandare e ricevere i pacchetti
* controllare binding update e binding refresh request
* fare il parsing di binding update

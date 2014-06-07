<p align="left"><img src="https://raw.github.com/krushserg/Toucan-Particle-System/master/img/logo.png"></p>
======================

c++11 abstract particle system


##основные понятия:
###1) randomizer
возвращает случайное значение (на самом деле по любым правилам)

###2) area
место жизни частиц

###3) emitter
указывает начальное состояние следующей частицы (возможно используя randomizer)

###4) affector
условно делится на 2 части.
* emitter affector (срабатывает 1 раз после создания частицы)
* area affector (работает всегда, возможно с учётом dt)

###5) drawer
делает что-то непонятное

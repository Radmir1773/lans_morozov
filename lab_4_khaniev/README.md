Требования к ПО для запуска симуляции:
- B&R Automation Studio 4.9.2.46 или новее
- Scene Viewer 4
- PVI 4.9

Порядок действий для запуска симуляции:
- Открыть Файл проекта URTKtry3.apj
- В среде Automation Studio открыть URTK_try.scn (находится по пути URTKFmu/URTKLib/URTK/)
- В открывшемся окне Scene Viewer перейти в Online -> OPC UA -> Connect...
- В окне подключеия выбрать Local -> B&R Embedded OPC-UA Server and Client -> None - None
- В среде Automation Studio для программы URTKPrg открыть Watch
- В окне Watch добавить переменную URTK1
- Задать значение "TRUE" переменной Enable
- Управление УРТК производится при помощи задания линейной скорости по 3 осям при помощи переменных Xinputvelocity, Yinputvelocity и Xinputvelocity

Переменные sensorX(x), sensorY(x) и sensorZ(x) симулируют работу концевых датчик по осям X, Y и Z соответственно.
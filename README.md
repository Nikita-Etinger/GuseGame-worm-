# Игра "Guse of war"

 В этой игре вы будете контролировать команду гусей и сражаться с другой командой гусей на рельефной карте. Ваша цель - уничтожить гусей соперника, используя разнообразное оружие и тактику.

## Правила игры

1. **Выбор позиции**: На вашем ходу вы можете перемещать своего гуся влево или вправо по рельефной карте. Для этого используйте клавиши **A** (движение влево) и **D** (движение вправо).

2. **Выбор направления выстрела**: После выбора позиции гуся, вы можете настроить направление выстрела. Используйте клавиши **Стрелка вверх** и **Стрелка вниз**, чтобы изменить угол наклона вашего выстрела.

3. **Выбор силы выстрела**: Подберите подходящую силу для вашего выстрела, чтобы точно поразить цель. Используйте клавиши **Стрелка влево** и **Стрелка вправо**, чтобы настроить силу выстрела.

4. **Разрушение земли**: Попадание вашего выстрела вызовет разрушение области земли. Это может быть использовано для изменения рельефа карты и облегчения попадания ваших выстрелов.

5. **Взаимодействие с гусем соперника**: При попадании выстрела в гуся соперника будет рассчитано расстояние до взрыва. Если взрыв заденет гуся, он будет отброшен в противоположную сторону. Если выстрел попадет непосредственно в гуся, отбрасывание не произойдет.

6. **Смена гусей**: После завершения хода текущего гуся, управление передается следующему гусю в вашей команде.

## Победа

Цель игры - уничтожить всех гусей в команде соперника. Выигрывает команда, оставшаяся с гусями после завершения сражения.

## Управление

- **A**: Движение гуся влево.
- **D**: Движение гуся вправо.
- **Стрелка вверх**: Изменение угла наклона выстрела.
- **Стрелка вниз**: Изменение угла наклона выстрела.
- **Стрелка влево**: Настройка силы выстрела.
- **Стрелка вправо**: Настройка силы выстрела.
- **Общая визуализация игры.**
![Sprite-0002](https://github.com/Nikita-Etinger/GuseGame-worm-/assets/113473133/b64c4993-f4e2-47c6-b1a6-2681e3aa83fe)

## Классы
- **Класс "Game" (Игра)**: Главный класс, который управляет ходом игры, включая инициализацию, обработку ввода, обновление состояния и отрисовку.

- **Класс "Player" (Игрок)**: Отвечает за управление гусем игрока, его перемещение и взаимодействие с окружением.

- **Класс "Landscape" (Ландшафт)**: Управляет рельефной картой, разрушением земли, созданием и уничтожением препятствий.

- **Класс "Weapon" (Оружие)**: Базовый класс для различных видов оружия. От него можно создать подклассы для разных типов оружия, таких как взрывчатые снаряды, стрелы и так далее.

- **Класс "Projectile" (Снаряд)**: Отвечает за физику снарядов, их движение, столкновения и воздействие на окружающую среду.

- **Класс "Charge" (Заряд)**: Можно назвать класс, отвечающий за настройку силы и направления выстрела. Например, "ShotPower" или "ProjectileSettings".

- **Класс "GameUI" (Игровой интерфейс)**: Отображает информацию для игрока, такую как текущее состояние, очки, текущий гусь и т.д.

- **Класс "GameManager" (Управление игрой)**: Может содержать логику уровней, переходы между гусями, обработку победы и поражения.

- **Класс "Explosion" (Взрыв)**: Может быть ответственным за создание эффектов взрыва, его радиус, повреждения и т.д.
  
## Задачи 
- **Реализовать генерацию плоской земли**.👍
- **Реализовать блок(спрайт) персонажа**.👍
- **Реализовать физику персонажа**(контакт с землёй).👍
- **Реализовать управление персонажем**.
- **Реализовать режим стрельбы**.

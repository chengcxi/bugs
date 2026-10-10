-- log_filter.lua
-- Catalog: script\multiplayer\modes
-- Modify by Max Drechsler 
-- Created 23.08.2026
-- Edited 24.08.2026
-- Version 2.5 (team assignment)

-- Переопределяет глобальную функцию print для подавления системного шума в логах

local M = {}

-- Список фраз, которые нужно скрыть (точное совпадение подстроки)
local BLOCKED_PHRASES = {
    "Localization key redefinition",
    "Entity redefinition",
    "Remap actor_id",
    "Undefined skin",
    "no breed found",
    "Unknown control panel item",
    "Actor human",
    "not registerd in unit manager",
    "unknown sound file 'vehicle/engine/tank",
    "medic_zone2: Static decal with non-constant sprite animator",
}

-- Сохраняем оригинальный print (если он уже был переопределён – берём его)
local original_print = print

-- Новая функция-фильтр
local function filtered_print(...)
    local args = {...}
    local msg = table.concat(args, " ")  -- собираем все аргументы в строку (как это делает print)
    
    -- Проверяем, содержит ли сообщение одну из запрещённых подстрок
    for _, phrase in ipairs(BLOCKED_PHRASES) do
        if string.find(msg, phrase, 1, true) then  -- true = обычный поиск без паттернов
            return  -- молча игнорируем
        end
    end
    
    -- Если сообщение не заблокировано – выводим через оригинальный print
    original_print(...)
end

-- Переопределяем глобальный print
_G.print = filtered_print

-- Экспортируем функцию для возможности сброса фильтра (если понадобится)
function M.reset()
    _G.print = original_print
end

function M.enable()
    _G.print = filtered_print
end

return M
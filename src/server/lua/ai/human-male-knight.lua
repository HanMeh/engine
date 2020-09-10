local module = {}

local shared = require "ai.shared"

function module.register()
  local name = "HUMAN_MALE_KNIGHT"
  local rootNode = AI.createTree(name):createRoot("PrioritySelector", name)
  shared.idlehome(rootNode)
end

return module

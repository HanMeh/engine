local module = {}

local shared = require "attrib.shared"

function module.register()
  local chr = attrib.createContainer("HUMAN_FEMALE_WORKER")
  shared.characterDefault(chr)
end

return module

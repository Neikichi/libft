-- load defaults i.e lua_lsp
require("nvchad.configs.lspconfig").defaults()

local lspconfig = require "lspconfig"

-- EXAMPLE
local servers = { "html", "cssls", "lua_ls", "pyright" } -- clangd is removed from this list
local nvlsp = require "nvchad.configs.lspconfig"

-- lsps with default config
for _, lsp in ipairs(servers) do
  lspconfig[lsp].setup {
    on_attach = nvlsp.on_attach,
    on_init = nvlsp.on_init,
    capabilities = nvlsp.capabilities,
  }
end

-- configuring clangd with additional arguments
lspconfig.clangd.setup {
  on_attach = nvlsp.on_attach,
  on_init = nvlsp.on_init,
  capabilities = nvlsp.capabilities,
  cmd = {
    vim.fn.stdpath("data") .. "/mason/bin/clangd", -- Use Mason's clangd
    -- "clangd", -- apt clangd
    -- "--compile-commands-dir=build", -- Adjust if necessary
    -- "--compile-arg=-Iinclude", -- Adds the "include/" directory for header files
    -- "--compile-arg=-Wall", -- Enable all warnings
    -- "--compile-arg=-Wextra", -- Enable extra warnings
    -- "--compile-arg=-Werror", -- Treat warnings as errors
  },
}

-- lspconfig.clangd.setup {
--   on_attach = nvlsp.on_attach,
--   on_init = nvlsp.on_init,
--   capabilities = nvlsp.capabilities,
--   cmd = {
--     vim.fn.stdpath("data") .. "/mason/bin/clangd"
--   },
--   init_options = {
--     fallbackFlags = {
--       "-Iinclude",  -- Adds the "include/" directory for header files
--       "-Wall",      -- Enable all warnings
--       "-Wextra",    -- Enable extra warnings
--       "-Werror"     -- Treat warnings as errors
--     },
--   },
-- }



vim.g.base46_cache = vim.fn.stdpath "data" .. "/base46/"
vim.g.mapleader = " "
vim.opt.clipboard = 'unnamedplus'
vim.g.python3_host_prog = vim.fn.expand("~/my_nvim_venv/bin/python3")
vim.keymap.set("i", "jj", "<Esc>", { silent = true })
vim.api.nvim_create_autocmd("FileType", {
  pattern = { "c", "cpp" },
  callback = function()
    vim.bo.commentstring = "// %s"
  end,
})



-- bootstrap lazy and all plugins
local lazypath = vim.fn.stdpath "data" .. "/lazy/lazy.nvim"

if not vim.uv.fs_stat(lazypath) then
  local repo = "https://github.com/folke/lazy.nvim.git"
  vim.fn.system { "git", "clone", "--filter=blob:none", repo, "--branch=stable", lazypath }
end

vim.opt.rtp:prepend(lazypath)

local lazy_config = require "configs.lazy"

-- load plugins
require("lazy").setup({
  {
    "NvChad/NvChad",
    lazy = false,
    branch = "v2.5",
    import = "nvchad.plugins",
  },

  { import = "plugins" },
}, lazy_config)

-- load theme
dofile(vim.g.base46_cache .. "defaults")
dofile(vim.g.base46_cache .. "statusline")

require "options"
require "nvchad.autocmds"

vim.schedule(function()
  require "mappings"
end)

-- Load stdheader.vim if available
local stdheader_path = vim.fn.expand("~/.vim/plugin/stdheader.vim")
if vim.fn.filereadable(stdheader_path) == 1 then
  vim.cmd("source " .. stdheader_path)
end

-- Automatically insert 42header for new files
vim.api.nvim_create_autocmd("BufNewFile", {
  pattern = { "*.c", "*.cpp", "*.h" },
  callback = function()
    vim.cmd("silent! 0r ~/.42header")
  end,
})

local dap = require("dap")

-- Use Mason's codelldb
dap.adapters.codelldb = {
    type = "server",
    port = "${port}",
    executable = {
        command = vim.fn.stdpath("data") .. "/mason/packages/codelldb/codelldb",
        args = { "--port", "${port}" },
    },
}

dap.configurations.cpp = {
    {
        name = "Launch file",
        type = "codelldb",
        request = "launch",
        program = function()
            return vim.fn.input("Path to executable: ", vim.fn.getcwd() .. "/", "file")
        end,
        cwd = "${workspaceFolder}",
        stopOnEntry = false,
    },
}

dap.configurations.c = dap.configurations.cpp


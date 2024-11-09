
return {
  {
    "stevearc/conform.nvim",
    -- event = 'BufWritePre', -- uncomment for format on save
    opts = require "configs.conform",
  },

  {
    "neovim/nvim-lspconfig",
    config = function()
      require "configs.lspconfig"
    end,
  },

  {
    "nvim-treesitter/nvim-treesitter",
    opts = {
      ensure_installed = {
        "vim", "lua", "vimdoc",
        "html", "css",
        "c", "cpp"   -- Adding C and C++
      },
    },
  },

  {
    "nvim-tree/nvim-tree.lua",
    config = function()
      require('nvim-tree').setup {
        git = {
          enable = true,
          timeout = 2000,  -- Set Git timeout to 2000 ms (2 seconds)
        },
      }
    end,
    dependencies = { "nvim-tree/nvim-web-devicons" },
  },

  -- Add null-ls.nvim for additional formatting and linting support 
  -- {
  --   "jose-elias-alvarez/null-ls.nvim",
  --   config = function()
  --     local null_ls = require("null-ls")
  --     null_ls.setup({
  --       debug = true,  -- Enable debug logging for troubleshooting
  --       sources = {
  --         null_ls.builtins.formatting.clang_format.with({
  --           filetypes = { "c", "cpp" },
  --           command = vim.fn.expand("~/.local/share/nvim/mason/bin/clang-format"),
  --           extra_args = {
  --             "--style={BasedOnStyle: Google, BreakBeforeBraces: Allman, IndentWidth: 4, ColumnLimit: 120}"
  --           },
  --         }),
  --       },
  --       on_attach = function(client, bufnr)
  --         if client.supports_method("textDocument/formatting") then
  --           -- Create the LspFormatting group if it doesn't exist
  --           local group = vim.api.nvim_create_augroup("LspFormatting", { clear = true })
  --           -- Clear any existing formatting autocommands for the buffer
  --           vim.api.nvim_clear_autocmds({ group = group, buffer = bufnr })
  --           -- Create a new autocommand for formatting before saving
  --           vim.api.nvim_create_autocmd("BufWritePre", {
  --             group = group,
  --             buffer = bufnr,
  --             callback = function()
  --               vim.lsp.buf.format({ async = false })
  --             end,
  --           })
  --         end
  --       end,
  --     })
  --   end,
  --   event = "BufReadPost",  -- Load null-ls when a buffer is read
  -- },
}


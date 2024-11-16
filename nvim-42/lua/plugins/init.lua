return {
  {
    "stevearc/conform.nvim",
    -- event = 'BufWritePre', -- uncomment for format on save
    opts = require "configs.conform",
  },

  -- These are some examples, uncomment them if you want to see them work!
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
          timeout = 500,  -- Set Git timeout to 2000 ms (2 seconds)
        },
      }
    end,
    dependencies = { "nvim-tree/nvim-web-devicons" },
  },

  -- Debugging Plugins
  -- Core DAP plugin
  {
    "mfussenegger/nvim-dap",
  },
  -- UI for nvim-dap
  {
    "rcarriga/nvim-dap-ui",
    dependencies = {
      "mfussenegger/nvim-dap",
      "nvim-neotest/nvim-nio", -- Add nvim-nio as a dependency for dap-ui
    },
    config = function()
      require("dapui").setup()
    end,
  },
  -- Inline virtual text for debugging
  {
    "theHamsta/nvim-dap-virtual-text",
    dependencies = { "mfussenegger/nvim-dap" },
    config = function()
      require("nvim-dap-virtual-text").setup()
    end,
  },
  -- Mason integration for managing debug adapters
  {
    "jay-babu/mason-nvim-dap.nvim",
    dependencies = { "williamboman/mason.nvim", "mfussenegger/nvim-dap" },
    config = function()
      require("mason-nvim-dap").setup {
        ensure_installed = { "codelldb" },
        automatic_setup = true,
      }
    end,
  },
  -- Telescope core plugin
  {
    "nvim-telescope/telescope.nvim",
    dependencies = { "nvim-lua/plenary.nvim" },
  },
  -- Telescope integration for nvim-dap
  {
    "nvim-telescope/telescope-dap.nvim",
    dependencies = {
      "mfussenegger/nvim-dap",
      "nvim-telescope/telescope.nvim",
    },
    config = function()
      require("telescope").load_extension("dap")
    end,
  },
	-- {
  -- 	"nvim-treesitter/nvim-treesitter",
  -- 	opts = {
  -- 		ensure_installed = {
  -- 			"vim", "lua", "vimdoc",
  --      "html", "css"
  -- 		},
  -- 	},
  -- },
}

" Specify the location of the plugins
call plug#begin('~/.local/share/nvim/plugged')

" Plugin List
" File Explorer
Plug 'nvim-tree/nvim-tree.lua'

" Fuzzy Finder
Plug 'nvim-telescope/telescope.nvim'
Plug 'nvim-lua/plenary.nvim'

" Status Line
Plug 'hoob3rt/lualine.nvim'

" Git Integration
Plug 'tpope/vim-fugitive'

" Autocompletion
Plug 'hrsh7th/nvim-cmp'
Plug 'hrsh7th/cmp-nvim-lsp'
Plug 'hrsh7th/cmp-buffer'
Plug 'hrsh7th/cmp-path'

" LSP Config
Plug 'neovim/nvim-lspconfig'

" Syntax Highlighting
Plug 'nvim-treesitter/nvim-treesitter', {'do': ':TSUpdate'}

" Commenting Utility
Plug 'tpope/vim-commentary'

" Surround Text Manipulation
Plug 'tpope/vim-surround'

" Plug 'yegappan/cproto'
" Plug 'git@github.com:yegappan/cproto.git'


call plug#end()

" General Settings
set number                       " Show line numbers
set relativenumber               " Show relative line numbers
set mouse=a                      " Enable mouse support
set clipboard=unnamedplus        " Use system clipboard
set tabstop=4                    " Set tab width to 4 spaces
set shiftwidth=4                 " Set indentation to 4 spaces
set expandtab                    " Convert tabs to spaces
set smartindent                  " Enable smart indentation
set cursorline                   " Highlight the current line
set splitright                   " Vertical splits open to the right
set splitbelow                   " Horizontal splits open below
syntax on                        " Enable syntax highlighting
filetype plugin indent on        " Enable plugins and filetype-specific indentation

" Key Mappings
" Set leader key to space
let mapleader = " "

" Better split navigation
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l

" Open nvim-tree with Ctrl + n
nnoremap <C-n> :NvimTreeToggle<CR>

" Telescope keybindings
nnoremap <leader>ff <cmd>Telescope find_files<CR>
nnoremap <leader>fg <cmd>Telescope live_grep<CR>

" Lualine setup
lua << EOF
require('lualine').setup {
  options = {
    theme = 'gruvbox',
  }
}
EOF

" LSP Setup
lua << EOF
local nvim_lsp = require('lspconfig')
nvim_lsp.pyright.setup{} -- Example LSP server for Python
EOF

" Treesitter setup
lua << EOF
require'nvim-treesitter.configs'.setup {
  ensure_installed = { "c", "cpp", "python", "lua", "javascript", "html", "css", "bash" },  -- Specify languages you need
  highlight = {
    enable = true,          -- Enable highlighting
  },
}
EOF


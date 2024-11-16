require "nvchad.mappings"

-- add yours here

local map = vim.keymap.set
local dap = require("dap")
local dapui = require("dapui")

-- Existing mappings
map("n", ";", ":", { desc = "CMD enter command mode" })
map("i", "jk", "<ESC>")

-- Debugging mappings
map("n", "<F5>", function() dap.continue() end, { desc = "Start/Continue Debugging" })
map("n", "<F10>", function() dap.step_over() end, { desc = "Step Over" })
map("n", "<F11>", function() dap.step_into() end, { desc = "Step Into" })
map("n", "<F12>", function() dap.step_out() end, { desc = "Step Out" })
map("n", "<Leader>db", function() dap.toggle_breakpoint() end, { desc = "Toggle Breakpoint" })
map("n", "<Leader>dB", function() dap.set_breakpoint(vim.fn.input("Breakpoint Condition: ")) end, { desc = "Set Conditional Breakpoint" })
map("n", "<Leader>dl", function() dap.set_breakpoint(nil, nil, vim.fn.input("Log Message: ")) end, { desc = "Set Log Point" })
map("n", "<Leader>dr", function() dap.repl.open() end, { desc = "Open REPL" })
map("n", "<Leader>du", function() dapui.toggle() end, { desc = "Toggle Debug UI" })
map("n", "<Leader>dc", function() dap.terminate(); dapui.close() end, { desc = "Stop Debugging and Close UI" })
map("n", "<Leader>dl", function() dap.run_last() end, { desc = "Run Last Debugging Session" })

-- Telescope DAP key mappings
map("n", "<Leader>df", ":Telescope dap frames<CR>", { desc = "DAP Frames" })
map("n", "<Leader>dbp", ":Telescope dap list_breakpoints<CR>", { desc = "List Breakpoints" })
map("n", "<Leader>dv", ":Telescope dap variables<CR>", { desc = "DAP Variables" })
map("n", "<Leader>dc", ":Telescope dap commands<CR>", { desc = "DAP Commands" })

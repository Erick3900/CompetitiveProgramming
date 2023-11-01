local function basename(filepath)
    local path = require('plenary.path')
    return tostring(path:new(filepath):parent())
end

return {
    {
        name = "configure",
        type = "shell",
        command = "cmake",
        args = {
            "-S " .. workspace_folder,
            "-B " .. ws.build_dir,
            "-DCMAKE_EXPORT_COMPILE_COMMANDS=1",
            "-DCMAKE_BUILD_TYPE=" .. state.build_mode
        },
        cwd = workspace_folder
    },
    {
        name = "build",
        type = "shell",
        command = "cmake",
        args = {
            "--build " .. ws.build_dir,
            "-j" .. number_of_cores,
        },
        cwd = ws.build_dir,
        depends = {
            "configure"
        },
        default = true,
    },
    {
        name = "clean",
        type = "shell",
        command = "cmake",
        args = {
            "--build " .. ws.build_dir,
            "--target clean"
        },
        cwd = ws.build_dir
    },
    {
        name = "new_problem",
        type = "lua",
        callback = function(runTask)
            local name = ""

            vim.ui.input({
                prompt = "Name: ",
                default = basename(file) .. dirsep,
            }, function(str)
                name = str
            end)

            runTask({
                name = "arti-gen cp-contest",
                type = "shell",
                command = "/opt/arti/generator/bin/arti-gen",
                args = {
                    "-t cp-problem",
                    "-n " .. name
                },
                cwd = workspace_folder
            }, function()
                vim.cmd(":e " .. name .. ".cpp")
            end)
        end
    },
    {
        name = "arti-gen",
        type = "lua",
        callback = function(runTask)
            local name = ""
            local template = ""

            vim.ui.input({
                prompt = "Template: ",
                default = "cp-problem"
            }, function(str)
                template = str
            end)

            vim.ui.input({
                prompt = "Name: ",
                default = basename(file) .. dirsep,
            }, function(str)
                name = str
            end)

            runTask({
                name = "arti-gen template",
                type = "shell",
                command = "/opt/arti/generator/bin/arti-gen",
                args = {
                    "-t " .. template,
                    "-n " .. name
                },
                cwd = workspace_folder
            }, function() end)
        end
    }
}

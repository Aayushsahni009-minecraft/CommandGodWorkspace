#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <iostream>

// Include our custom Workspace engines
#include "ManifestGenerator.h"
#include "TextureManager.h"

int main() {
    // [GLFW Window Initialization Code Goes Here]
    // [ImGui Context Setup Code Goes Here]

    std::string generatedJson = "";

    // Main Application Loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Start new ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Build the Workspace UI
        ImGui::Begin("Command God Workspace - Tools");

        if (ImGui::CollapsingHeader("JSON Generator")) {
            ImGui::Text("Generate a standard Behavior Pack Manifest:");
            if (ImGui::Button("Generate Manifest")) {
                generatedJson = ManifestGenerator::CreateBehaviorPackManifest("My Epic Addon", "Built with CG Workspace");
            }
            
            // Display the generated JSON in a read-only text box
            if (!generatedJson.empty()) {
                ImGui::InputTextMultiline("Output", &generatedJson[0], generatedJson.size(), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16), ImGuiInputTextFlags_ReadOnly);
            }
        }

        if (ImGui::CollapsingHeader("Texture Manager")) {
            ImGui::Text("Test STB Image Loading:");
            if (ImGui::Button("Load Test Texture (dirt.png)")) {
                // Assuming you have a dirt.png in your assets folder
                TextureManager::InspectTexture("assets/dirt.png");
            }
        }

        ImGui::End();

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // Cleanup code
    return 0;
}
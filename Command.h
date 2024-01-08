#pragma once

class Command{

    public:
        //метод за изпълнение на командата
        virtual void execute() = 0;

        virtual ~Command() = default;
};